/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:53:20 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 21:36:45 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	*this = other;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
		for (int i = 0; i < MAX_MATERIA; i++) {
			if (this->_materia[i])
				delete this->_materia[i];
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (!this->_materia[i]) {
			this->_materia[i] = m;
			break ;
		}
	}
}

void	MateriaSource::forgetMateria(int idx) {
	if (idx >= 0 && idx < MAX_MATERIA) {
		if (this->_materia[idx]) {
			delete this->_materia[idx];
			this->_materia[idx] = NULL;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}
