/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:22:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/16 20:02:59 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                sign;
        const int           GradeSign;
        const int           GradeExecute;

    public:
        Form(void);
        ~Form(void);
        Form(const Form &other);
        Form &operator=(const Form &other);

        Form(const std::string name, const int  GradeSign, const int GradeExecute);
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
        void        beSigned(Bureaucrat &other);
        bool        GetSign() const;
        std::string GetName() const;
        int         GetGradeSign() const;
        int         GetGradeExecute() const;
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif