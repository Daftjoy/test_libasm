/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:38:07 by antmarti          #+#    #+#             */
/*   Updated: 2020/08/14 19:33:20 by amaresp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	check_write(void)
{
	char *hello_world;
	char *empty;
	int fd;

	hello_world = "Coucou\n";
	empty = "";
	fd = open("text.txt", O_WRONLY);
	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, hello_world, 7));
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(fd, "jsafjaskf", 0));
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(fd, "asjfnasjfasjk", 0));
	printf("\n");
	close(fd);
	fd = open("wrong.txt",O_WRONLY);
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(fd, NULL, 7));
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(fd, NULL, 7));
}

void	check_read(void)
{
	int		fd;
	char	buff1[891];
	int		ret;

	fd = open("main.c", O_RDONLY);
	ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	printf("%-20s: \n", "header main.c | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	close(fd);
	fd = open("main.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header main.c | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	clear_buffer(buff1, 891);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	printf("%-20s: \n", "file test | libc ");
	check_read_aux(fd, read(1, buff1, 890), buff1);
}

void	check_read_aux(int fd, int ret, char *buff1)
{
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "file test | libasm ");
	ret = ft_read(1, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	clear_buffer(buff1, 891);
	close(fd);
	fd = open("wrong", O_RDONLY);
	printf("%-20s: \n", "wrong | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "wrong | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n\n", ret, buff1);
	clear_buffer(buff1, 891);
	close(fd);
}

void	check_strdup(void)
{
	char *save;

	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", "Hello world !");
	save = strdup("Hello worldjsfasfksklsnfnsalfnsalkfsakfnasklfnasklsnfkasfasklfmkdamsaklfksak !");
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save = ft_strdup("Hello world asnfkasnfknaklsnfsaklnfksanslfklasnfsnlafnaksnfksnalkfnslkan !");
	printf("%-20s: \"%s\"\n", "libasm", save);
	free(save);
	save = NULL;
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", "");
	save = strdup("");
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save = ft_strdup("");
	printf("%-20s: \"%s\"\n", "libasm", save);
	free(save);
	save = NULL;
	printf("\n");
}

int		main(void)
{
	errno = 0;
	check_read();
	check_strcmp();
	check_strcpy();
	check_strdup();
	check_strlen();
	check_write();
}
