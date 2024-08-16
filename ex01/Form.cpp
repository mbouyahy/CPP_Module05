/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:22:49 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/19 15:07:39 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("42"), sign(false), GradeSign(1), GradeExecute(1)
{
    std::cout << "Form : Default Constructor" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form : Destructor Called" << std::endl;
}

Form::Form(const Form &other) : name(other.GetName()), GradeSign(other.GetGradeSign()), GradeExecute(other.GetGradeExecute())
{
    *this = other;
    std::cout << "Form : Copy Constructor Called" << std::endl;
}

Form::Form(std::string name, int  GradeSign, int GradeExecute) : name(name), sign(false), GradeSign(GradeSign), GradeExecute(GradeExecute)
{
    std::cout << "Form : Parametrized Constructor Called" << std::endl;
    if (GradeSign < 1 || GradeExecute < 1)
        throw GradeTooHighException();
    if (GradeExecute > 150 || GradeSign > 150)
        throw GradeTooLowException();
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Form : Copy Assignment Called" << std::endl;
    if (this != &other)
    {
        this->sign = other.sign;
    }
    return (*this);
}

void    Form::beSigned(Bureaucrat &other)
{
    //Remember, grade 1 is higher than grade 2
    if (other.GetGrade() <= this->GetGradeSign())
    {
        this->sign = true;
    }
    if (other.GetGrade() > this->GetGradeSign())
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Error : the grade is out of the range => too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Error : the grade is out of the range => too low");
}

bool        Form::GetSign() const
{
    return (sign);
}

std::string Form::GetName() const
{
    return (name);
}

int   Form::GetGradeSign() const
{
    return (GradeSign);
}

int   Form::GetGradeExecute() const
{
    return (GradeExecute);
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
    out 
        << "Form Name : "
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