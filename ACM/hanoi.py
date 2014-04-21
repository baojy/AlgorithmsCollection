import sys
def hanoi(n,A,B,C):
	if n==1:
		print 'move sheet ',n,' from ',A,' to ',C
	else :
		hanoi(n-1,A,C,B)
		print 'move sheet ',n,' from ',A,' to ',C
		hanoi(n-1,B,A,C)
def main():
	hanoi(3,'A','B','C')
	print '\n'
	hanoi(4,'A','B','C')

if __name__=='__main__':
	main()
