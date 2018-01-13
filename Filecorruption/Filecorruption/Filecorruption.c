#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
	{
		FILE *fp;
		double size;
		char *b; 
		size_t items_read;
		double linevalue;
		int i;
		double percent = 0;
		linevalue = 0;

		fp=fopen("usblarger4 copy 4.bin","rb");
		if (!fp)
		{
			printf("Unable to open file!");
			return 1;
		}
		else 
		{ 
			fseek(fp, 0, SEEK_END);
			size=ftell(fp);
			rewind(fp);
			b=(char*)malloc(size);
			items_read = fread(b,1,size,fp);
			fclose(fp);
			
			for (i=0; i<size; i++)
				/*printf("%d ", b[i]);*/
				if (b[i] != 48)
				{
					linevalue++;
				}
		}
		
		printf("%lf\n", size);
		printf("%lf\n", linevalue);

		percent=(linevalue/size)*100;
		printf("%.10lf percent of the file is corrupted\n", percent);
		 
		

		printf("Press ENTER key to Continue\n");  
		getchar();

		return 10;
	}