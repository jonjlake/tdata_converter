#include <stdlib.h>
#include "C:\\CPP\\wav_reader\\wav_reader.h"
#include "C:\\CPP\\fft\\fft.h"
#include "tdata_converter.h"

/* Main task: convert "short" to "double" */

/* Is this the appropriate place to allocate the sample_array? */
void convert_channel_samples_to_sample_doubles(WaveFile *p_wavefile, FourierData **p_fourier_data_array)
{
	int i,j;
	
	*p_fourier_data_array = (FourierData *)calloc(p_wavefile->num_channels, sizeof(**p_fourier_data_array));

	for (i = 0; i < p_wavefile->num_channels; i++)
	{
		(*p_fourier_data_array)[i].sample_array = calloc(p_wavefile->num_frames, 
			sizeof(*(*p_fourier_data_array)[i].sample_array));
	
		(*p_fourier_data_array)[i].num_samples = p_wavefile->num_frames;
		(*p_fourier_data_array)[i].dt = p_wavefile->dt;

		for (j = 0; j < p_wavefile->num_frames; j++)
		{
			(*p_fourier_data_array)[i].sample_array[j] = (double)p_wavefile->channel_samples[i][j];
		}
	}		

	
}

void convert_sample_doubles_to_channel_shorts(WaveFile *p_wavefile, FourierData *fourier_data_array)
{
	int i, j;

	/* Assume previous allocation */
	for (i = 0; i < p_wavefile->num_channels; i++)
	{
		for (j = 0; j < p_wavefile->num_frames; j++)
		{
			p_wavefile->channel_samples[i][j] = (short int)fourier_data_array[i].sample_ift[j].re;
//			printf("fourier real %f converted to wavefile short %d\n", 
					fourier_data_array[i].sample_ift[j].re, p_wavefile->channel_samples[i][j]);
		}
	}
}

#if 0
int main()
{
	return 0;
}
#endif
