
import random
East=['C','F','G','W']
West=[]
Forbidden=[['C','G','W'],['C','G'],['G','W']]






def PrintContains(East,West):
    
    print ('East:')
    for x in East:
        print (x,end=' ')
    print ('\nWest:')
    for x in West:
        print (x,end=' ')
    print('\n')
        
    
    
   
    return
#Go west: Complete this function according to the instructions on HW4
def GoWest(East,West):
    
    flagf = True

    while flagf == True:
        entity= 'F'
        while entity =='F':
            entity=random.choice(East)

        
        
        West.append(entity)
        East.remove(entity)

        West.append('F')
        East.remove('F')
        
        for x in Forbidden:
            if x == East:
                flagf = True
                East.append(entity)
                West.remove(entity)
                East.append ('F')
                West.remove ('F')
                East.sort()
                
                
            else:
                flagf= False
            if flagf == True:
                break
    West.sort()
    PrintContains(East,West)
    print('-------------------------------------\n')
    return  East, West



#Go East: Complete this function according to the instructions on HW4   
def GoEast(East,West):
    West.remove('F')
    East.append ('F')
    
        
    for x in Forbidden:
        if x == West:
            entw=random.choice(West)
            West.remove(entw)
            East.append(entw)
            West.sort()
            
                
     
   
   
   
    East.sort()   
    PrintContains(East,West)
    print('-------------------------------------\n')    
    return  East, West



# Solution: This function returns True if all objects are on the West side otherwise returns False (One line of code)    
def Solution():
    if len(East) == 0:return True



#DO not change anything in the following lines. Your job is to complete the functions above.
PrintContains(East,West)
print('-------------------------------------')  
condition=True
while condition:
    East, West=GoWest(East,West)
    if not Solution():
       East, West=GoEast(East,West)
    else:
     condition=False











