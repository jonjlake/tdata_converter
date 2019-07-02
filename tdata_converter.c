#include <stdlib.h>
#include "wav_reader.h"
#include "fft.h"

/* Main task: convert "short" to "double" */

void short_to_double(short **input_arrays, double ***output_arrays, int num_channels,
		int num_elements))
{
	int i, j;

	for (i = 0; i < num_channels; i++)
	{
		for (j = 0; j < num_elements)
		{
			(*output_arrays)[i][j] = (double)input_arrays[i][j];
		}
	}
}

void convert_channel_samples_to_sample_doubles(WaveFile *p_wavefile, otherdata)
{
	short_to_double(p_wavefile->channel_samples, &output_arrays,
			p_wavefile->num_channels,
			p_wavefile->data_section_size / p_wavefile->bitrate_math);
}

