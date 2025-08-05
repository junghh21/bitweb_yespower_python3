#include "yespower.h"
#include "sysendian.h"
#include <stdio.h>
static const yespower_params_t v1 = {YESPOWER_1_0, 2048, 8, NULL, 0};
static const yespower_params_t v2 = {YESPOWER_1_0, 2048, 32, NULL, 0};
int y1_foo(const uint8_t *input, uint8_t *output, unsigned int *no, unsigned int *mask)
{
		//yespower_tls( (yespower_binary_t*)input, 80, &v1, (yespower_binary_t*)output );
		return yespower_tls((yespower_binary_t *)input, 80, &v2, (yespower_binary_t *) output);
}

int y1_foo2(const uint8_t *input, uint8_t *output, unsigned int *no, unsigned int *mask)
{
	unsigned int *a = input;
	unsigned int *b = output;
	unsigned int i;
	for(i=*no;i<(*no)+1000;i++)
	{
		a[19] = i;
		yespower_tls((yespower_binary_t *)input, 80, &v2, (yespower_binary_t *) output);
		//printf("%08X : %08X, %08X\n", i, b[7], *mask);
		if (b[7] < *mask)
		{
			*mask = b[7];  
			*no = i;
			//printf("%08X : %08X : %08X, %08X\n", i, *no, b[7], *mask);
			return 0;
		} 
	}
	*no = i-1;
	//printf("%08X : %08X : %08X, %08X\n", i, *no, b[7], *mask);
	return -1;
}
/*int yespower_hash(const char *input, char *output)
{
	uint32_t time = le32dec(&input[68]);
	if (time > 1676761800) {
		return yespower_tls(input, 80, &v1, (yespower_binary_t *) output);
	} else {
		return yespower_tls(input, 80, &v2, (yespower_binary_t *) output);
	}
}
*/

