#A program that contains a class that will manage questions and of the answer to said question is right it will award a point.

class Question:
    def __init__(self, quest, ans1, ans2, ans3, ans4, right):
        self.__question = quest
        self.__answer1 = ans1
        self.__answer2 = ans2
        self.__answer3 = ans3
        self.__answer4 = ans4
        self.__right = right
     
    #accesors

    def getquest(self):
        return self.__question

    def getans1(self):
        return self.__answer1

    def getans2(self):
        return self.__answer2

    def getans3(self):
        return self.__answer3

    def getans4(self):
        return self.__answer4

    def getright(self):
        return self.__right


    #__str__ method
    def __str__(self):
        return '{} \n1. {} \n2. {} \n3. {} \n4. {} \n'.format(self.__question, self.__answer1, self.__answer2, self.__answer3, self.__answer4)















            
