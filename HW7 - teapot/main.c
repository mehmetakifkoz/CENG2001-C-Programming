#include <stdio.h>
#include <stdlib.h>

struct float_Point3D
{
    float x;
    float y;
    float z;
};

struct int_Point3D
{
    int x;
    int y;
    int z;
};

void update(FILE *input_file_pointer,
            int number_of_vertices,
            int number_of_faces,
            struct float_Point3D *vertices,
            struct int_Point3D *faces,
            struct float_Point3D *center_of_mass,
            float x,
            float y,
            float z);

int main()
{
    printf("*Translocation by Mehmet Akif KOZ 192010010023\n");
    printf("*This program reads an obj file, computes the center of mass of the model and translates the model in given x,y,z direction.\n");
    printf("*Instructions: Type the translocation values and press \"Enter\".\n");
    printf("\n");

    FILE *input_file_pointer = fopen("teapot.obj", "r");
    if (input_file_pointer == NULL)
    {
        printf("ERROR: Cannot read teapot.obj\n");
        exit(1);
    }

    char ch;
    int number_of_vertices = 0;
    int number_of_faces = 0;
    struct float_Point3D center_of_mass;

    // User inputs
    float x;
    float y;
    float z;

    while (!feof(input_file_pointer))
    {
        ch = fgetc(input_file_pointer);
        if (ch == 'v')
        {
            number_of_vertices++;
        }
        else if (ch == 'f')
        {
            number_of_faces++;
        }
    }

    struct float_Point3D *vertices = calloc(number_of_vertices, sizeof(struct float_Point3D));
    struct int_Point3D *faces = calloc(number_of_faces, sizeof(struct int_Point3D));

    update(input_file_pointer, number_of_vertices, number_of_faces, vertices, faces, &center_of_mass, 0, 0, 0);

    printf("Input Center of Mass:\nx = %f\ny = %f\nz = %f\n", center_of_mass.x, center_of_mass.y, center_of_mass.z);

    printf("\n");

    printf("Translocate:\n");
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("z = ");
    scanf("%f", &z);

    printf("\n");

    update(input_file_pointer, number_of_vertices, number_of_faces, vertices, faces, &center_of_mass, x, y, z);

    printf("Output Center of Mass:\nx = %f\ny = %f\nz = %f\n", center_of_mass.x, center_of_mass.y, center_of_mass.z);

    fclose(input_file_pointer);

    FILE *output_file_pointer = fopen("HW_7_192010010023_MEHMET_AKIF_KOZ.obj", "w");
    if (output_file_pointer == NULL)
    {
        printf("ERROR: Cannot write HW_7_192010010023_MEHMET_AKIF_KOZ.obj\n");
        exit(2);
    }

    for (int i = 0; i < number_of_vertices; i++)
    {
        fprintf(output_file_pointer, "v %f %f %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
    }

    fprintf(output_file_pointer, "\n");

    for (int j = 0; j < number_of_faces; j++)
    {
        fprintf(output_file_pointer, "f %d %d %d\n", faces[j].x, faces[j].y, faces[j].z);
    }

    fclose(output_file_pointer);

    return 0;
}

void update(FILE *input_file_pointer,
            int number_of_vertices,
            int number_of_faces,
            struct float_Point3D *vertices,
            struct int_Point3D *faces,
            struct float_Point3D *center_of_mass,
            float x,
            float y,
            float z)
{
    rewind(input_file_pointer);

    char ch;

    center_of_mass->x = 0;
    center_of_mass->y = 0;
    center_of_mass->z = 0;

    int i = 0;
    int j = 0;
    while (!feof(input_file_pointer))
    {
        ch = fgetc(input_file_pointer);
        if (ch == 'v')
        {
            fscanf(input_file_pointer, "%f", &vertices[i].x);
            fscanf(input_file_pointer, "%f", &vertices[i].y);
            fscanf(input_file_pointer, "%f", &vertices[i].z);

            vertices[i].x += x;
            vertices[i].y += y;
            vertices[i].z += z;

            center_of_mass->x += vertices[i].x / number_of_vertices;
            center_of_mass->y += vertices[i].y / number_of_vertices;
            center_of_mass->z += vertices[i].z / number_of_vertices;

            i++;
        }
        else if (ch == 'f')
        {
            fscanf(input_file_pointer, "%d", &faces[j].x);
            fscanf(input_file_pointer, "%d", &faces[j].y);
            fscanf(input_file_pointer, "%d", &faces[j].z);
            j++;
        }
    }
}
