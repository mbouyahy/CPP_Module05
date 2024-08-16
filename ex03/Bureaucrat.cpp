/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:32:42 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/21 11:34:23 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("TESING")
{
    std::cout << "Default Constructor" << std::endl;
    grade = 1;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    *this = other;
    std::cout << "Copy Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    std::cout << "Parametrize Constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::GetGrade() const
{
    return (grade);
}

void    Bureaucrat::Increment_Grade()
{
    int temp;

    temp = grade - 1;
    if (temp < 1)
        throw GradeTooHighException();
    if (temp > 150)
        throw GradeTooLowException();
    grade--;
}

void    Bureaucrat::Decrement_Grade()
{
    int temp;

    temp = grade + 1;
    if (temp < 1)
        throw GradeTooHighException();
    if (temp > 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("the grade is out of the range => too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("the grade is out of the range => too low");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy Assignment called" << std::endl;
    if (this != &other)
    {
        // (std::string)name = other.name;
        this->grade = other.grade;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.GetGrade() << std::endl;
    return (out);
}

void    Bureaucrat::signForm( AForm &other)
{
    try
    {
        other.beSigned(*this);
        std::cout << this->name << " Signed " << other.GetName() << std::endl;
    }
    catch (GradeTooLowException &e)
    {
        std::cout << this->name << " Couldn't sign " << other.GetName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->name  << " executed " << form.GetName() << std::endl;
    }
    catch (AForm::GradeTooLowException &e)
    {
       std::cout << this->name << " Couldn't execute " << form.GetName() << " because " << e.what() << std::endl;
    }
}