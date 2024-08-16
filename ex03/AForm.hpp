/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:22:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/19 19:17:48 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                sign;
        const int           GradeSign;
        const int           GradeExecute;

    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        AForm(const std::string name, const int  GradeSign, const int GradeExecute);
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class FormSignException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class CreateFileException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        virtual void    execute(Bureaucrat const & executor) const = 0;
        void            beSigned(const Bureaucrat &other);
        bool            GetSign() const;
        std::string     GetName() const;
        int             GetGradeSign() const;
        int             GetGradeExecute() const;
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif