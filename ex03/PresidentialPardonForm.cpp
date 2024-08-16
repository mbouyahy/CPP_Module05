/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:28:59 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/20 15:45:34 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Required grades: sign 25, exec 5
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential", 25, 5)
{
    std::cout << "PresidentialPardonForm : Default Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm : Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    *this = other;
    std::cout << "PresidentialPardonForm : Copy Constructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm : Copy Assignment Called" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
    this->target = target;
    std::cout << "PresidentialPardonForm : Parametrized Called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!GetSign())
        throw FormSignException();
    if (executor.GetGrade() > this->GetGradeExecute())
    {
        throw GradeTooLowException();
    }
    else
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}