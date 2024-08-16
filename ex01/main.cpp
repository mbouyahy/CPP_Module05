/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:41:12 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/20 14:55:25 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Br("Br01", 20);
        Form F("form01", 30, 30);
        Br.signForm(F);
        std::cout << F;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}