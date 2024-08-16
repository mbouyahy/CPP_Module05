/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:18:01 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/19 19:17:07 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Required grades: sign 145, exec 137
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("TEST", 145, 137)
{
    std::cout << "ShrubberyCreationForm : Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm : Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    *this = other;
    std::cout << "ShrubberyCreationForm : Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm : Copy Assignment Called" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 145, 137)
{
    this->target = target;
    std::cout << "ShrubberyCreationForm : Parametrized Constructor Called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!GetSign())
        throw FormSignException();
    if (executor.GetGrade() > this->GetGradeExecute())
        throw GradeTooLowException();
    std::ofstream file(target + "_shrubbery");
    if (!file)
        throw CreateFileException();
    file << "        *      " << std::endl;
    file << "       ***     " << std::endl;
    file << "      *****    " << std::endl;
    file << "     *******    " << std::endl;
    file << "    *********   " << std::endl;
    file << "   ***********    " << std::endl;
    file << "        *    " << std::endl;
    file << "        *    " << std::endl;
    file << "        *    " << std::endl;
    file.close();
}