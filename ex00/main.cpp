/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:41:12 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/28 11:35:50 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat B("First_B", 1);

        // Bureaucrat A = B;
        // std::cout << A << std::endl;
        // std::cout << B << std::endl;
        std::cout << std::endl << "the garde before calling Decrement_Grade() or Increment_Grade() : " << B << std::endl;
        B.Decrement_Grade();
        std::cout << "the garde after calling Decrement_Grade() : " << B << std::endl;

        B.Increment_Grade();
        std::cout << "the garde after calling Increment_Grade() : " << B << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}