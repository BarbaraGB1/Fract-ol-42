/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:53:35 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 23:48:19 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	print_resume(void)
{
	ft_printf("\n           *   INPUTS THAT I NEED TO FUNCTION   *\n");
	ft_printf("   ______________________________________________________   \n");
	ft_printf(".´                                                        `.\n");
	ft_printf("|                                                          |\n");
	ft_printf("|        In this program, you can run two fractals:        |\n");
	ft_printf("|                                                          |\n");
	ft_printf("|              --> 'Mandelbrot and Julia' <--       *      |\n");
	ft_printf("|                                                 * * *    |\n");
	ft_printf("|                                             * *       *  |\n");
	ft_printf("|                                        *** *   *     *   |\n");
	ft_printf("| -MANDELBROT                                 * *       *  |\n");
	ft_printf("| INPUTS: [name of program] Mandelbrot            * * *    |\n");
	ft_printf("|                                                   *      |\n");
	ft_printf("| -JULIA:                                                  |\n");
	ft_printf("| INPUTS: [name of program] Julia [param1] [param2]        |\n");
	ft_printf("|                                                          |\n");
	ft_printf(" `. ____________________________________________________ .´ \n");
}

void	print_examples(void)
{
	ft_printf(".´                                                        `.\n");
	ft_printf("|                                                          |\n");
	ft_printf("|  [EXAMPLES]                                              |\n");
	ft_printf("|                                                          |\n");
	ft_printf("|  ./fractol Mandelbrot                                    |\n");
	ft_printf("|  ./fractol Julia 1.0 -0.8                                |\n");
	ft_printf("|                                                          |\n");
	ft_printf(" `. ____________________________________________________ .´ \n");
}

void	print_controls(void)
{
	ft_printf("   ______________________________________________________   \n");
	ft_printf(".´                                                        `.\n");
	ft_printf("|                                                  ___     |\n");
	ft_printf("|                       CONTROLS                  |[_]|    |\n");
	ft_printf("|                                                 |+ ;|    |\n");
	ft_printf("|                                                 `---'    |\n");
	ft_printf("|                                                          |\n");
	ft_printf("|     [Moves]                        [Zoom]                |\n");
	ft_printf("|        -UP    = W                     -IN  = O           |\n");
	ft_printf("|        -DOWN  = S                     -OUT = P           |\n");
	ft_printf("|        -RIGHT = A                     -SCROLL MOUSE      |\n");
	ft_printf("|        -LEFT  = D                                        |\n");
	ft_printf("|                                                          |\n");
	ft_printf("|     [Iters]                      [Colors]                |\n");
	ft_printf("|        -Plus = +                      - 1, 2, 3, 4       |\n");
	ft_printf("|        -Less = -                                         |\n");
	ft_printf("|                                                          |\n");
	ft_printf("|     [Restart]                    [Close]                 |\n");
	ft_printf("|        - R                            - X in window      |\n");
	ft_printf("|                                       - ESC              |\n");
	ft_printf("|                                                          |\n");
	ft_printf(" `.______________________________________________________.´ \n");
	ft_printf("\n");
}

void	print_remenber(void)
{
	ft_printf(".´                                                        `.\n");
	ft_printf("| Remenber:                                                |\n");
	ft_printf("|                                                          |\n");
	ft_printf("| -The size does matter, if you see an uppercase letter,   |\n");
	ft_printf("|  it's there for a reason.                                |\n");
	ft_printf("| -Param1 and param2:                                      |\n");
	ft_printf("|   1- Must be numbers.                                    |\n");
	ft_printf("|   2- Must have a minimum length of ~1~                   |\n");
	ft_printf("|      and a maximum length of ~10~.                       |\n");
	ft_printf(" `. ____________________________________________________ .´ \n");
	ft_printf("\n");
	ft_printf("           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~           \n");
	ft_printf("        .´                                        `.        \n");
	ft_printf("        |          FOR SEE CONTROLS ENTER          |        \n");
	ft_printf("        |                   YES                    |        \n");
	ft_printf("        |             FOR CLOSE ENTER              |        \n");
	ft_printf("        |                   NO                     |        \n");
	ft_printf("        `.                                        .´\n");
	ft_printf("           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_printf("\n");
}

void	print_message(void)
{
	print_resume();
	print_examples();
	print_remenber();
	do_gnl();
}
