#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main() {
	key_t key;
	size_t size = 201;
	int shmid;
	char *data;
	key = ftok(".", 'R');
	shmid = shmget(key, size, 0666 | IPC_CREAT);
	data = shmat(shmid, (void*)0, 0);
	printf("Contents of shared memory: [%s]\n", data);
	if (!data[0]) {
		printf("This segment was just created!\n");
	}
	printf("Do you wish to change data in the segment?[y/n]\n");
	char user_says[202];
	fgets(user_says,201, stdin);
	if (user_says[0] == 'y') {
		printf("Write new segment\n");
		fgets(user_says, 201, stdin);
		user_says[strlen(user_says)-1] = '\0';
		strcpy(data, user_says);
	}
	printf("Do you wish to delete the data in the segment?[y/n]\n");
	fgets(user_says,201,stdin);
	if (user_says[0] == 'y') {
		shmctl(shmid, IPC_RMID, NULL);
	}
	return 0;
}