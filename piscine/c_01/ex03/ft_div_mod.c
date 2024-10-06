/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:07:17 by mivogel           #+#    #+#             */
/*   Updated: 2024/06/28 11:19:52 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int main(){
	int a;
	int b;
	a = 826;
	b = 10;

	int d;
	int m;
	int *div = &d;
	int *mod = &m;
	ft_div_mod(a, b, div, mod);
	printf("%d,%d", *div, *mod);
}*/
