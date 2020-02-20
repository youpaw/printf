/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_classifier.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:44:49 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:46:31 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_CLASSIFIER_H
# define DOUBLE_CLASSIFIER_H

# include <stdint.h>
# include "double_representation.h"

typedef struct
{
	uint8_t		sign;
	uint32_t	exponent;
	uint8_t		bit63;
	uint8_t		bits63_62;
	uint64_t	bits62_0;
	uint64_t	bits61_0;
}	t_double_parts;

t_double_parts	get_double_parts(t_double_bit d);

#endif
