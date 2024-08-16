/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:22:49 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/07 14:07:46 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("42"), sign(false), GradeSign(1), GradeExecute(1)
{
    std::cout << "AForm : Default Constructor" << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "AForm : Destructor Called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.GetName()), GradeSign(other.GetGradeSign()), GradeExecute(other.GetGradeExecute())
{
    *this = other;
    std::cout << "AForm : Copy Constructor Called" << std::endl;
}

AForm::AForm(std::string name, int  GradeSign, int GradeExecute) : name(name), sign(false), GradeSign(GradeSign), GradeExecute(GradeExecute)
{
    if (GradeSign < 1 || GradeExecute < 1)
        throw GradeTooHighException();
    if (GradeExecute > 150 || GradeSign > 150)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("the grade is out of the range => too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("the grade is out of the range => too low");
}

const char *AForm::FormSignException::what() const throw()
{
    return ("The Form is Not Signed");
}

const char *AForm::CreateFileException::what() const throw()
{
    return ("Create file fails!");
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm : Copy Assignment Called" << std::endl;
    if (this != &other)
    {
        this->sign = other.sign;
    }
    return (*this);
}

void    AForm::beSigned(const Bureaucrat &other)
{
    if (other.GetGrade() > this->GetGradeSign())
        throw GradeTooLowException();
    this->sign = true;
}

bool        AForm::GetSign() const
{
    return (sign);
}
std::string AForm::GetName() const
{
    return (name);
}
int   AForm::GetGradeSign() const
{
    return (GradeSign);
}
int   AForm::GetGradeExecute() const
{
    return (GradeExecute);
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
    out 
        << "AForm Name : "
        << other.GetName()
        << " | Grade required to sign it : "
        << other.GetGradeSign()
        << " | grade required to execute it : "
        << other.GetGradeExecute()
        << " | Sign : "
        << other.GetSign()
        << std::endl;
    return (out);
}