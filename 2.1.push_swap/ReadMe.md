# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ReadMe.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 19:33:55 by uuenkhba          #+#    #+#              #
#    Updated: 2026/01/15 22:37:50 by uuenkhba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Push_Swap

#### Project Overview

Subject says: "This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting."

**Note**: The program does not return a sorted stack but a list of operations that were performed.

#### Algorithm Choice

For my project, I chose Mechanical Turk algorithm, which is very efficient and well-explained in [the article of A. Yigit Ogun (Hellibronn)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

I use only two types of instructions - case of both rotations and case of both reverse rotations. These instructions have two variations each, for sorting in descending order (stack b) and for sorting in ascending order (stack a).

#### Valid inputs
1) `./push_swap 5 4 3 2 1`
2) `./push_swap "5 4 3 2 1"`
__________________________________________________________________________________

#### To count the number of operations use this command:

```./push_swap 5 4 3 2 1 | wc -l```
__________________________________________________________________________________

#### List of errors.

The program returns specific error codes for different types of errors. `echo $?` to display exit status.

Error 1: No input provided.\
Error 2: Input contains only one argument and it is not a number.\
Error 3: Input consists of a mix of arguments and strings, e.g., `4 3 -200 "-66 0" 3`\
Error 4: Duplicate values in stack a.\
Error 5: Memory allocation failure.\
Error 127: Invalid number (error during `atoi` conversion).

The program returns 0 on success.

###For My Self
Энэ функц бол рандом 500 хүртэлх давхцаагүй тоог хамгийн бага үйлдлээр эрэмблэх үүрэгтэй программ бичих бөгөөд 2 стак байх ба стак_а д байгаа тоог стак_б д түр хадгалаад буцаагаад агаа дүүргэж эрэмбэлхэд хамгийн бага үйлдэл үзүүлж байгаа сортлох теори ашиглах ёстой. би Турк гэсэн хүний хийсэн теори ашигласан бөгөөд программ хэрхэн сортолсон үйлдлүүдийг буцаах болно. хэд хэдэн алдааны мэдээлэл буцаах дүрэмтэйг бас санах хэрэгтэй.
