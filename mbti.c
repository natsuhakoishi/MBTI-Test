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
	char	c;

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
	printf("Answer all (total 150) Question with a score between 1 ~ 9.\n");
	printf("Scoring tips: 1 for Strongly Disagree, 5 for Neutral, 9 for Strongly Agree.\n\n");
	printf("Do you ready to answer the question? (y/n): ");
	scanf("%c", &c);
	while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
	{
		printf("\nInvalid input.\nPlease enter a valid character (y/n): ");
		if (scanf(" %c", &c) != 1)
		{
			while (getchar() != '\n')
				continue;
		}
		else
			getchar();
	}
	if (c == 'n' || c == 'N')
	{
		printf("\nSee you later !\n\n");
		return (1);
	}

	while ((line = get_next_line(fileno(question))) != NULL)
	{
		input = 0;
		printf("\nQuestion %d: %s\n", ++ques_count, line);
		free(line);
		printf("Your answer (1~9) > ");
		scanf("%d", &input);
		while (input < 1 || input > 9)
		{
			printf("\nInvalid input.\nPlease enter a valid number (1~9) > ");
			if (scanf("%d", &input) != 1)
			{
				while (getchar() != '\n')
				{
					printf("\nInvalid input.\nPlease enter a valid number (1~9) > ");
					continue;
				}
			}
			printf("\n");
		}
		if ((ques_count >= 1 && ques_count <= 20) || (ques_count >= 81 && ques_count <= 90) || \
				ques_count == 121 || ques_count == 131 || ques_count == 132 || ques_count == 133 || \
				ques_count == 135 || ques_count == 136 || ques_count == 138 || ques_count == 139 || \
				ques_count == 142) //E vs I
		{
			score[0] += input;
			max[0] += 9;
		}
		else if ((ques_count >= 21 && ques_count <= 40) || (ques_count >= 91 && ques_count <= 100) || \
					ques_count == 144 || ques_count == 145 || ques_count == 148) //S vs N
		{
			score[1] += input;
			max[1] += 9;
		}
		else if ((ques_count >= 41 && ques_count <= 60) || (ques_count >= 101 && ques_count <= 110) || \
					ques_count == 124 || ques_count == 149) //T vs F
		{
			score[2] += input;
			max[2] += 9;
		}
		else if ((ques_count >= 61 && ques_count <= 80) || (ques_count >= 111 && ques_count <= 120) || \
				ques_count == 123 || ques_count == 125 || ques_count == 127 || ques_count == 128 || \
				ques_count == 129 || ques_count == 134 || ques_count == 137 || ques_count == 140 || \
				ques_count == 141 || ques_count == 146 || ques_count == 150) //J vs P
		{
			score[3] += input;
			max[3] += 9;
		}
		else if (ques_count == 130 || ques_count == 143)
		{
			score[0] += 9 - input;
			max[0] += 9;
		}
		else if (ques_count == 147)
		{
			score[2] += 9 - input;
			max[2] += 9;
		}
		else if (ques_count == 122 || ques_count == 126)
		{
			score[3] += 9 - input;
			max[3] += 9;
		}
		else if (ques_count > 150)
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
