/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:28:17 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/20 15:45:57 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Required grades: sign 72, exec 45
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45)
{
    std::cout << "RobotomyRequestForm : Default Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm : Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    *this = other;
    std::cout << "RobotomyRequestForm : Copy Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm : Copy Assignment Called" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
    this->target = target;
    std::cout << "RobotomyRequestForm : Parametrized Called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!GetSign())
        throw FormSignException();
    if (executor.GetGrade() > this->GetGradeExecute())
    {
        throw GradeTooLowException();
    }
    else
    {
        static int robot;
        if (robot % 2 == 0)
            std::cout << target << " has been robotomized successfull" << std::endl;
        else
            std::cout << "Robotomy failed" << std::endl;
        robot++;
    }
}
