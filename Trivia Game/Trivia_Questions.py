#A program that contains the questions, the answer choices, and the right answers, and will use the class to put them together and append them to a list


import Question

def qlist():
    qst = []
    
    q1 = Question.Question('How many days are in a lunar year? ', 379, 243, 354, 365, 3)
    qst.append(q1)
    
    q2 = Question.Question('What is the largest planet? ', 'Jupiter', 'Mars', 'Pluto', 'Earth', 1)
    qst.append(q2)
    
    q3 = Question.Question('What is the largest kind of whale? ', 'Humpback Whale', 'Beluga Whale', 'Orca Whale', 'Blue Whale', 4)
    qst.append(q3)
    
    q4 = Question.Question('Which dinosaur could fly? ', 'Diplodocus', 'Pteranodon', 'T-Rex', 'Triceratops', 2)
    qst.append(q4)
    
    q5 = Question.Question('Which of these Winnie the Pooh characters is a donkey? ', 'Eeyore', 'Pooh', 'Kanga', 'Piglet', 1)
    qst.append(q5)
    
    q6 = Question.Question('What is the hottest planet? ', 'Venus', 'Mars', 'Pluto', 'Earth', 1)
    qst.append(q6)
    
    q7 = Question.Question('Which dinosaur had the largest brain compared to body size? ', 'Stegosaurus', 'Gigantoraptor', 'Ichthyosaurus', 'Troodon', 4)
    qst.append(q7)
    
    q8 = Question.Question('What is the largest type of penguins?', 'White-Flippered Penguins', 'Macaroni Penguins', 'Emperor Penguins', 'Chinstrap Penguins', 3)
    qst.append(q8)
    
    q9 = Question.Question("Which children's story character is a monkey?", 'Goofy', 'Horton', 'Winnie The Pooh', 'Curious George', 4)
    qst.append(q9)
    
    q10 = Question.Question('How long is a year on Mars? ', '687 Earth Days', '550 Earth Days', '126 Earth Days', '498 Earth Days', 1)
    qst.append(q10)

    return qst



















    























    
    
