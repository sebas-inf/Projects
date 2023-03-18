#A program that will run a trivia game for 2 people, 5 questions for each player, and will count how many answers each players get right and also
#tell them if they got an answer wrong and what the correct one was, at the end it will tell the player who won or if it was a tie, it will say that it was a tie.

import Question

from Trivia_Questions import qlist

def main():
    qst = qlist()
    p1p = 0
    p2p = 0

    for i in range(10):

        if i % 2 ==0:
            print('Question for the first player: ')
            print(qst[i])
            ans = int(input('Enter your solution (a number between 1 and 4): '))
            while ans < 1 or ans > 4:
                ans = int(input('Please Re-enter your solution (a number between 1 and 4): '))
                
            if ans == qst[i].getright():
                print('That is the correct answer!')
                p1p +=1
            else:
                print('That is incorrect. The correct answer is ',qst[i].getright())
        else:
            print('Question for the Second Player:')
            print(qst[i])
            ans = int(input('Enter your solution (a number between 1 and 4): '))
            while ans < 1 or ans > 4:
                ans = int(input('Please Re-enter your solution (a number between 1 and 4): '))
            if ans == qst[i].getright():
                print('That is the correct answer!')
                p2p +=1
            else:
                print('That is incorrect. The correct answer is ',qst[i].getright())

    print('The First Player earned', p1p , 'points.')
    print('The Second Player earned', p2p , 'points.')

    if p1p > p2p:
        print('The First Player wins the game!!!')

    elif p2p > p1p:
        print('The Second Player wins the game!!!')

    elif p1p == p2p:
        print("It's a tie")

#call main()
main()
        
            
            




















    
    
