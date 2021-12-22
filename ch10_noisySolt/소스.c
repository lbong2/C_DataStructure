#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void InsertionSort(float* arr , int length) {
	int i, j;
	float key;

	for (i = 1; i < length; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) {       
				arr[j + 1] = arr[j];  
			}
			else {                  
				break;
			}
		}
		arr[j + 1] = key;          
	}
}

void median_filtering(float* input, float* tmp, int width, int height) {

	for (int i = 1; i < width - 1; i++) {
		for (int j = 1; j < height - 1; j++) {
			tmp[0] = input[(i - 1) * width + j - 1];
			tmp[1] = input[(i - 1) * width + j];
			tmp[2] = input[(i - 1) * width + j + 1];
			tmp[3] = input[i * width + j - 1];
			tmp[4] = input[i * width + j];
			tmp[5] = input[i * width + j + 1];
			tmp[6] = input[(i + 1) * width + j - 1];
			tmp[7] = input[(i + 1) * width + j];
			tmp[8] = input[(i + 1) * width + j + 1];
			
			InsertionSort(tmp, 9);

			input[i * width + j] = tmp[4];
		}
	}
}
void read_file(float* input, int height, int width, char filename[])
{
	int x, y;
	FILE* fp;
	fp = fopen(filename, "r");
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			fscanf(fp, "%f", &input[y * width + x]);
		}
		fscanf(fp, "\n");
	}
	fclose(fp);
}
void main()
{
	int height = 44, width = 45; // image width and height

	char* fname = "noisy_data.txt";
	float tmp[9];
	float* input;

	input = (float*)malloc(width * height * sizeof(float));
	read_file(input, height, width, "noisy_data.txt");
	median_filtering(input, tmp, width, height);
	
	FILE* outF;
	outF = fopen("result.txt", "wt");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fprintf(outF, "%.2f ", input[i * width + j]);
		}
		fprintf(outF, "\n");
	}
	fclose(outF);


	free(input);


}
