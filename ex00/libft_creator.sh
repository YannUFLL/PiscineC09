# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 16:32:41 by ydumaine          #+#    #+#              #
#    Updated: 2022/02/03 16:34:21 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c *.c
ar rc libft.a *.o
rm *.o 
