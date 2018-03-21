/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:30:32 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:11:54 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

cl_float4	cross(cl_float4 u, cl_float4 v)
{
	cl_float4	ret;

	ret.x = (u.y * v.z) - (u.z * v.y);
	ret.y = (u.z * v.x) - (u.x * v.z);
	ret.z = (u.x * v.y) - (u.y * v.x);
	ret.w = 0.0;
	return (ret);
}

cl_float4	mult(cl_float4 u, cl_float mult)
{
	cl_float4	ret;

	ret.x = u.x * mult;
	ret.y = u.y * mult;
	ret.z = u.z * mult;
	ret.w = 0.0;
	return (ret);
}

cl_float4	add(cl_float4 u, cl_float4 v)
{
	cl_float4	ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;
	ret.z = u.z + v.z;
	ret.w = 0.0;
	return (ret);
}

cl_float4	minus(cl_float4 u, cl_float4 v)
{
	cl_float4	ret;

	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	ret.z = u.z - v.z;
	ret.w = 0.0;
	return (ret);
}
