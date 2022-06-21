#include "philosophers.h"

int	error(char *str);

int Global;
pthread_mutex_t  lock_a;

void *Thread1(void *x) {

	int i = 10;

	pthread_mutex_lock(&lock_a);
	Global++;
	printf("Thread 1\n");
	pthread_mutex_unlock(&lock_a);
	return NULL;
}

void *Thread2(void *x) {

	int i = 20;

	pthread_mutex_lock(&lock_a);
	Global--;
	printf("Thread 2\n");
	pthread_mutex_unlock(&lock_a);
	return NULL;
}

int	main(int argc, char **argv)
{
	pthread_t	t[2];
	t_input		input;


	if (argc != 5 && argc != 6)
		return (error("Error : Invalid input\n"));
	input = init_input(argc, argv);
	if (!input.count)
		return (error("Error : Invalid input\n"));


	pthread_mutex_init(&lock_a, 0);
	pthread_create(&t[0], NULL, Thread1, NULL);
	pthread_create(&t[1], NULL, Thread2, NULL);
	printf("Test\n");
	printf("Test git\n");
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	return (0);
}
