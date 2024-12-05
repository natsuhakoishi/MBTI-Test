# include <stdio.h>
# include <stdlib.h>
# include "gnl.h"

void	result(int score[4], int max[4])
{
	float	ei = ((float)score[0] / max[0]) * 100;
	float	sn = ((float)score[1] / max[1]) * 100;
	float	tf = ((float)score[2] / max[2]) * 100;
	float	jp = ((float)score[3] / max[3]) * 100;

	printf("\nYour MBTI type is: ");
	printf("%c", (ei >= 50.0) ? 'E' : 'I');
	printf("%c", (sn >= 50.0) ? 'S' : 'N');
	printf("%c", (tf >= 50.0) ? 'T' : 'F');
	printf("%c\n\n", (jp >= 50.0) ? 'J' : 'P');

	printf("Result Details\n");
	printf("Extroversion: %.1f%% | Introversion: %.1f%%\n", ei, (100.0 - ei));
	printf("Sensing: %.1f%% | Intuition: %.1f%%\n", sn, (100.0 - sn));
	printf("Thinking: %.1f%% | Feeling: %.1f%%\n", tf, (100.0 - tf));
	printf("Judging: %.1f%% | Perceiving: %.1f%%\n\n", jp, (100.0 - jp));

	printf("Feel free to check more of your MBTI details in Google!\n");
	printf("Thanks for using MBTI Test Program by NatsuhaKoishi\n");
}

int	main(int argc, char **argv)
{
	int		score[4] = {0, 0, 0, 0};
	int		max[4] = {0, 0, 0, 0};
	// 0 E vs I
	// 1 S vs N
	// 2 T vs F
	// 3 J vs P
	char	*line;
	int		input;
	int		ques_count = 0;

	(void)argv;
	if (argc != 1)
	{
		printf("\nError.\nUsage: ./mbti\n\n");
		return (1);
	}
	FILE *question = fopen("question.txt", "r");
	if (!question)
	{
		perror("Error: Failure Loading Question.");
		return (1);
	}
	printf("\nWelcome to MBTI Test Program by NatsuhaKoishi\n");
	printf("Answer all (total 90) Question with a score between 1 ~ 10.\n\n");
	while ((line = get_next_line(fileno(question))) != NULL)
	{
		input = 0;
		printf("\nQuestion %d: %s\n", ++ques_count, line);
		free(line);
		printf("Your answer (1~10) > ");
		scanf("%d", &input);
		while (input < 1 || input > 10)
		{
			printf("\nInvalid input.\nPlease enter a valid number (1~10) > ");
			if (scanf("%d", &input) != 1)
			{
				while (getchar() != '\n')
				{
					printf("\nInvalid input.\nPlease enter a valid number (1~10) > ");
					continue;
				}
			}
			printf("\n");
		}
		if (ques_count >= 1 && ques_count <= 10) //E vs I
		{
			score[0] += input;
			max[0] += 10;
		}
		else if ((ques_count >= 11 && ques_count <= 20) || ques_count == 65 || \
					ques_count == 71 || ques_count == 72 || ques_count == 74 || \
					ques_count == 85 || ques_count == 88) //S vs N
		{
			score[1] += input;
			max[1] += 10;
		}
		else if ((ques_count >= 21 && ques_count <= 30) || ques_count == 60 || \
					ques_count == 64 || ques_count ==  67 || ques_count == 70 || \
					ques_count == 73 || ques_count == 75 || ques_count ==  80) //T vs F
		{
			score[2] += input;
			max[2] += 10;
		}
		else if ((ques_count >= 31 && ques_count <= 40) || ques_count == 61 || \
					ques_count == 66 || ques_count == 68 || ques_count == 76 || \
					ques_count == 77 || ques_count == 81 || ques_count == 82 || \
					ques_count == 89 || ques_count == 90) //J vs P
		{
			score[3] += input;
			max[3] += 10;
		}
		else if (ques_count >= 41 && ques_count <= 43)
		{
			score[0] += input;
			score[1] += input;
			max[0] += 10;
			max[1] += 10;
		}
		else if (ques_count >= 44 && ques_count <= 46)
		{
			score[0] += 10 - input;
			score[1] += 10 - input;
			max[0] += 10;
			max[1] += 10;
		}
		else if (ques_count >= 47 && ques_count <= 49)
		{
			score[2] += input;
			score[1] += input;
			max[2] += 10;
			max[1] += 10;
		}
		else if (ques_count >= 50 && ques_count <= 52)
		{
			score[2] += 10 - input;
			score[1] += 10 - input;
			max[2] += 10;
			max[1] += 10;
		}
		else if (ques_count >= 53 && ques_count <= 55)
		{
			score[2] += input;
			score[3] += input;
			max[2] += 10;
			max[3] += 10;
		}
		else if (ques_count >= 56 && ques_count <= 58)
		{
			score[2] += 10 - input;
			score[3] += 10 - input;
			max[2] += 10;
			max[3] += 10;
		}
		else if (ques_count == 59 || ques_count == 63 || ques_count == 69 || \
					ques_count == 78 || ques_count == 79 || ques_count == 83 || \
					ques_count == 84 || ques_count == 86 || ques_count == 87)
		{
			score[0] += 10 - input;
			max[0] += 10;
		}
		else if (ques_count == 62)
		{
			score[1] += 10 - input;
			max[1] += 10;
		}
		else if (ques_count > 90)
		{
			printf("\nNumber of line in the Question File exceeded.\n");
			printf("\nProgram session will be terminate.\n\n");
			return (0);
		}
	}
	fclose(question);
	result(score, max);
	return (0);
}
