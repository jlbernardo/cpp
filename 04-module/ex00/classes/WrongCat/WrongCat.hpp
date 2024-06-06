/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:23:32 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 22:02:15 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

/**
 * #### WrongCat class, derived from WrongAnimal
 * It tries to override the makeSound method to make a wrong cat sound
 */
class WrongCat : public WrongAnimal {

public:
				/**
				 * @brief Constructs a new WrongCat object.
				 */
				WrongCat(void);

				/**
				 * @brief Destroys the WrongCat object.
				 */
				~WrongCat(void);

				/**
				 * @brief Constructs a new WrongCat object from the copy received.
				 * @param copy The WrongCat to copy from.
				 */
				WrongCat(const WrongCat &copy);

				/**
				 * @brief Copies everything from the WrongCat received.
				 * @param copy The WrongCat to copy from.
				 */
	void		operator=(const WrongCat &copy);


				/**
				 * @brief It... Quacks?
				 */
	void		makeSound(void) const;

};

#endif
