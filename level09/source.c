#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "msg.h"

int secret_backdoor()
{
	char s[128];

	fgets(s, 128, stdin);
	return (system(s));
}

char *set_msg(t_msg msg)
{
	char s[1024];

	memset(s, 0, sizeof(s));
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(s, 1024, stdin);
	return strncpy(msg.message, s, msg.length);
}

int set_username(t_msg msg)
{
	char s[140];
	int i;

	memset(s, 0, 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(s, 128, stdin);
	for (i = 0; i <= 40 && s[i]; ++i)
		*(msg.username + i) = s[i];
	return printf(">: Welcome, %s", msg.username);
}

int handle_msg()
{
	t_msg message = {
		.length = 140
	};

	set_username(message);
	set_msg(message);
	return puts(">: Msg sent!");
}

int main()
{
	puts(
		"--------------------------------------------\n"
		"|   ~Welcome to l33t-m$n ~    v1337        |\n"
		"--------------------------------------------"
	);
	handle_msg();
	return (0);
}
