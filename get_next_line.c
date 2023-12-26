#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	char sentence[BUFFER_SIZE];
	int	letter_counter;
	int	sentence_counter;
	int available_chars;
	letter_counter = 0;
	sentence_counter = 0;

	while(letter_counter < BUFFER_SIZE)
	{
		available_chars = BUFFER_SIZE - letter_counter;
		read(0, sentence, available_chars);
		write(1, sentence, available_chars);
		sentence_counter++;
		letter_counter += ft_strlen(sentence) - sentence_counter;

	}
}