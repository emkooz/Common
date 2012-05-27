#include "Model.h"

bool loadOBJ (const char* filepath , std::vector <glm::vec3> &OutVerts,
											std::vector <glm::vec2> &OutUV,
											std::vector <glm::vec3> &OutNormals)
{
	std::cout << "\n.OBJ: Loading " << filepath;

	std::vector <unsigned int> vertexIndices , uvIndices , normalIndices;
	std::vector <glm::vec3> temp_vertices;
	std::vector <glm::vec2> temp_uvs;                                  // temporary data
	std::vector <glm::vec3>temp_normals;

	FILE * file = fopen (filepath , "r"); // open the file
	if (file == NULL)
	{
		std::cout << "\nCannot open the file! Unknown error.";
		return false;
	}

	while (true)
	{
		char LineHeader [512]; // lines

		int res = fscanf (file , "%s" , LineHeader); // scan the line
		if (res = EOF) 
			break; // End of the file! Lets quit scanning.

		if (strcmp (LineHeader , "v") == 0) // Does the line start with "v" (vert)?
		{ // If so...
			glm::vec3 Vertex; // temporary variable

			fscanf (file , "%f %f %f\n" , &Vertex.x , &Vertex.y , &Vertex.z); // look at the coordinates and put them in the temp variable
			temp_vertices.push_back (Vertex); // Now lets push to our main temporary variable 
		}

		else if (strcmp (LineHeader , "vt") == 0)
		{
			glm::vec2 UV;

			fscanf (file , "%f %f\n" , &UV.x , &UV.y);
			temp_uvs.push_back (UV);
		}

		else if (strcmp (LineHeader , "vn") == 0)
		{
			glm::vec3 Normal;

			fscanf (file , "%f %f %f\n" , &Normal.x , &Normal.y , &Normal.z);
			temp_normals.push_back (Normal);
		}

		else if (strcmp (LineHeader  , "f" ) == 0) // faces
		{
			std::string Vertex1 , Vertex2 , Vertex3;
			unsigned int vertexIndex[3] , uvIndex[3] , normalIndex[3];

			int matches = fscanf (file , "%d %d %d  %d %d %d  %d %d %d\n" , &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9)
			{
				std::cout << "\nOBJ: Cannot properly read " << file << ", try exporting differently.";
				return false;
			}
						vertexIndices.push_back(vertexIndex[0]);
                        vertexIndices.push_back(vertexIndex[1]);
                        vertexIndices.push_back(vertexIndex[2]);
                        uvIndices    .push_back(uvIndex[0]);
                        uvIndices    .push_back(uvIndex[1]);
                        uvIndices    .push_back(uvIndex[2]);
                        normalIndices.push_back(normalIndex[0]);
                        normalIndices.push_back(normalIndex[1]);
                        normalIndices.push_back(normalIndex[2]);
		}

		else //just a comment
		{
			char BadBuffer [1000];
			fgets (BadBuffer , 1000 , file);
		}

		for (unsigned int a = 0; a < vertexIndices.size(); a++)
		{
			unsigned int VertIndex = vertexIndices[a];
			unsigned int UVIndex = uvIndices[a];
			unsigned int NormalIndex = normalIndices[a];

			glm::vec3 vertex = temp_vertices[VertIndex - 1];
			glm::vec2 uv = temp_uvs [UVIndex - 1];
			glm::vec3 normal = temp_normals [NormalIndex - 1];

			OutVerts.push_back (vertex);
			OutUV.push_back (uv);
			OutNormals.push_back (normal);
		}
	}

	return true;
}