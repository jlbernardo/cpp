# The Diamond Problem

Multiple inheritance is a feature of some object-oriented programming languages in which an object or class can inherit features from more than one parent object or parent class.

The "**[diamond problem](https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem)**" (sometimes referred to as the "Deadly Diamond of Death") is an ambiguity that arises when two classes B and C inherit from A, and class D inherits from both B and C. If there is a method in A that B and C have inherited and passed over to D, which version of the method does D uses: that of B, or that of C?

<p align="center">
  <img src="https://cdn.discordapp.com/attachments/819418940987670558/1247399108231299123/diamond_problem_1.png?ex=665fe272&is=665e90f2&hm=e0318fb3bb5b2a0d3d9ad2aee0a3eae1ddbb8827d3b421fc71d1d6f143037da3&" />
</p>

Different languages ​​solve this problem in different ways. Python, for example, follows a specific order to traverse the class hierarchy - the [Method Resolution Order (MRO)](https://medium.com/@suryansaravanan/method-resolution-order-mro-in-python-25f82af58c49).

C++ uses the [virtual](https://learn.microsoft.com/en-us/cpp/cpp/virtual-cpp?view=msvc-170) keyword before the class inheritance declaration, meaning that child classes receive only one instance of the common base class. In other words, instead of `Class D` receiving two instances of `Class A` (one from `Class B` and one from `Class C`), it only receives it once, eliminating any hierarchical conflict.
<br><br>

### This exercise aims to demonstrate the diamond problem in C++.

Here, we create a base class called $ClapTrap$ and two derived classes, $FragTrap$ and $ScavTrap$, which both inherit from $ClapTrap$. Finally, we create a class called DiamondTrap, which inherits from both $FragTrap$ and $ScavTrap$.

Diamond is able to access the members of both Frag and Scav classes, as well as the members of the Clap. This is possible because the Frag and Scav classes inherit from Clap using the `virtual` keyword, whichmakes so Diamond only receives one instance of Clap.
<br><br>

## The game!

<br>
<p align="center">
  <img src="https://cdn.discordapp.com/attachments/819418940987670558/1247418513258188871/ezgif.com-video-to-gif-converter_2.gif?ex=665ff485&is=665ea305&hm=676ee7dcc8ae423c780ec94079707adc5ed658143bfafaf1a9c28fbd79ec2580&" />
</p>

<br><br>
Open your terminal and clone the repository to your local machine using the command below.

```bash
git clone git@github.com:jlbernardo/cpp.git
```

Navigate to `03-module` folder (you can check the other modules too, if you want) and enter each exercise's directory, they range from 00 to 03. Type `make run` to compile and run the program.
<br><br>

### Each exercise has a mechanic:

`ex00` This is a simple fight betweent two robots of base class, they can attack each other, recover health points and upgrade their damage.

`ex01` All previous actions are available, but your enemy can also enter gate keeping mode, where it will deal the same amount of damage it receives on that turn.

`ex02` The new mechanic is that your opponent may offer you a high five (check gif above). If you accept it, both of you will receive a random buff; but if you refuse it, they will only buff themselves and attack you.

`ex03` This is the final battle! Your opponent has access to every mechanic implemented so far, as is inherits from all of the existing classes. It is also scared and quite strong, but I trust your ability to defeat it!

<br>

### Controls

| Key | Action |
| --- | --- |
| `A` | Attacks your opponent with your current damage points. |
| `H` | Heals your character by a random amount. |
| `U` | Upgrades your damage points by a random amount. |
| `E` | Exits the phase. |
| `A` or `R` | While on high five prompt, you can press `A` to accept or `R` to reject. |
