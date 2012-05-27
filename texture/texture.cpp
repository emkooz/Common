#include "texture.h"

Texture::Texture()
{
	programID = Texture::LoadShaders ("tex.vert" , "tex.frag");
	img = SOIL_load_OGL_texture("runner_01.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	
	Verts.push_back (glm::vec2 (-1.0f , -1.0f));
	Verts.push_back (glm::vec2 (-1.0f , 1.0f));
	Verts.push_back (glm::vec2 (1.0f , 1.0f));
	Verts.push_back (glm::vec2 (1.0f , -1.0f));
	
	UV.push_back (glm::vec2 (0.0f , 1.0f));
	UV.push_back (glm::vec2 (0.0f , 0.0f));
	UV.push_back (glm::vec2 (1.0f , 0.0f));
	UV.push_back (glm::vec2 (1.0f , 1.0f));
	
	// Vert buffer
	glGenBuffers (1 , &VertBuffer);
	glBindBuffer (GL_ARRAY_BUFFER, VertBuffer);
	glBufferData (GL_ARRAY_BUFFER , Verts.size()*sizeof(glm::vec2) , &Verts[0] , GL_STATIC_DRAW);
	
	// UV buffer
	glGenBuffers (1 , &UVBuffer);
	glBindBuffer (GL_ARRAY_BUFFER , UVBuffer);
	glBufferData (GL_ARRAY_BUFFER , UV.size()*sizeof(glm::vec2) , &UV[0] , GL_STATIC_DRAW);
}

void Texture::Draw()
{
	if (programID == 0) // Was not able to compile, fallback.
		{
		glEnableClientState (GL_VERTEX_ARRAY);
		glBindBuffer (GL_ARRAY_BUFFER , VertBuffer);
		glVertexPointer (2 , GL_FLOAT , 0 , NULL);

		glEnableClientState (GL_TEXTURE_COORD_ARRAY);
		glBindBuffer (GL_ARRAY_BUFFER , UVBuffer);
		glTexCoordPointer (2 , GL_FLOAT , 0 , NULL);

		glEnable (GL_TEXTURE_2D);
		glBindTexture (GL_TEXTURE_2D , img);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(1,1,1,1);
		glDrawArrays (GL_QUADS , 0 , Verts.size());

		glDisable (GL_TEXTURE_2D);
		glDisable(GL_BLEND);

		glDisableClientState (GL_VERTEX_ARRAY);
		glDisableClientState (GL_TEXTURE_COORD_ARRAY);
		}
		
		else // Is able to compile.
		{
			glUseProgram (programID);
			
					   glActiveTexture (GL_TEXTURE0);
	   glBindTexture (GL_TEXTURE_2D , img);
	   glUniform1i (img , 0);

	   glEnableVertexAttribArray (0);
	   glBindBuffer (GL_ARRAY_BUFFER , VertBuffer);
	   glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 0 , NULL);

	   glEnableVertexAttribArray (1);
	   glBindBuffer (GL_ARRAY_BUFFER , UVBuffer);
	   glVertexAttribPointer ( 1 , 2 , GL_FLOAT , GL_FALSE , 0 , NULL);


	   glEnable(GL_BLEND);
	   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	   glEnable(GL_TEXTURE_2D);
		 glDrawArrays (GL_QUADS , 0 , Verts.size());
	   glDisable(GL_TEXTURE_2D);
	   glDisable(GL_BLEND);

	   glDisableVertexAttribArray (0);
	   glDisableVertexAttribArray (1);
		}	
}

GLuint Texture::LoadShaders (const char * vertex_file_path,const char * fragment_file_path)
{
		 // Create the shaders
        GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        // Read the Vertex Shader code from the file
        std::string VertexShaderCode;
        std::ifstream VertexShaderStream (vertex_file_path);
        if(VertexShaderStream.is_open()){
                std::string Line = "";
                while(getline(VertexShaderStream, Line))
                        VertexShaderCode += "\n" + Line;
                VertexShaderStream.close();
        }

        // Read the Fragment Shader code from the file
        std::string FragmentShaderCode;
        std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
        if(FragmentShaderStream.is_open()){
                std::string Line = "";
                while(getline(FragmentShaderStream, Line))
                        FragmentShaderCode += "\n" + Line;
                FragmentShaderStream.close();
        }



        GLint Result;
        int InfoLogLength;



        // Compile Vertex Shader
        printf("Compiling shader: %s\n", vertex_file_path);
        char const * VertexSourcePointer = VertexShaderCode.c_str();
        glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
        glCompileShader(VertexShaderID);

        // Check Vertex Shader
        glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> VertexShaderErrorMessage(InfoLogLength);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);
        
        if (Result == GL_FALSE)
        {
			std::cout << "Vertex shader was unable to compile!\n";
			return 0;
		}




        // Compile Fragment Shader
        printf("Compiling shader: %s\n", fragment_file_path);
        char const * FragmentSourcePointer = FragmentShaderCode.c_str();
        glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
        glCompileShader(FragmentShaderID);

        // Check Fragment Shader
        glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);


		if (Result == GL_FALSE)
		{
			std::cout << "Fragment shader was unable to compile!\n";
			return 0;
		}
		


        // Link the program
        fprintf(stdout, "Linking program\n");
        GLuint ProgramID = glCreateProgram();
        glAttachShader(ProgramID, VertexShaderID);
        glAttachShader(ProgramID, FragmentShaderID);
        glLinkProgram(ProgramID);

        // Check the program
        glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
        glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> ProgramErrorMessage( std::max(InfoLogLength, int(1)) );
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
        
        if (Result == GL_FALSE)
        {
			std::cout << "Shaders were unable to link!\n";
			return 0;
		}


        glDeleteShader(VertexShaderID);
        glDeleteShader(FragmentShaderID);

        return ProgramID;
}
