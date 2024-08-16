/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:41:12 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/19 16:27:26 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat Br_Presidential("Br_Presidential", 4);
        Bureaucrat Br_Shrubbery("Br_Shrubbery", 40);
        Bureaucrat Br_Robotomy("Br_Robotomy", 40);

        std::cout << std::endl;
        AForm *Presidential = new PresidentialPardonForm("PresidentialPardon");
        // Presidential->execute(Br_Presidential);
        Presidential->beSigned(Br_Presidential);
        Br_Presidential.executeForm(*Presidential);
        std::cout << *Presidential;

        std::cout << std::endl;
        AForm *Shrubbery = new ShrubberyCreationForm("ShrubberyCreation");
        // Shrubbery->execute(Br_Shrubbery);
        Shrubbery->beSigned(Br_Shrubbery);
        Br_Shrubbery.executeForm(*Shrubbery);
        std::cout << *Shrubbery;
        
        std::cout << std::endl;
        AForm *Robotomy = new RobotomyRequestForm("RobotomyRequest");
        // Robotomy->execute(Br_Robotomy);
        Robotomy->beSigned(Br_Robotomy);
        Br_Robotomy.executeForm(*Robotomy);
        std::cout << *Robotomy;

        std::cout << std::endl;
        delete Robotomy;
        std::cout << std::endl;
        delete Presidential;
        std::cout << std::endl;
        delete Shrubbery;
        std::cout << std::endl;
        
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}