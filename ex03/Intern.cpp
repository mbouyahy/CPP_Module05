/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:32:50 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/09 13:18:33 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern : Default Constructor Called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern : Destructor Called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    *this = other;
    std::cout << "Intern : Copy Constructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern : Copy Assignement Called" << std::endl;
    if (this != &other)
    {

    }
    return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string Forms[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        if (Forms[i] == name)
            break ;
    }
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << Forms[i] << std::endl;
            return (new PresidentialPardonForm(target));
        case 1:
            std::cout << "Intern creates " << Forms[i] << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << Forms[i] << std::endl;
            return (new ShrubberyCreationForm(target));
        default:
            std::cout << "Intern Fails!" << std::endl;
    }
    return (NULL);
}
