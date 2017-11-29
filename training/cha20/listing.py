def Readlines(file):
    fl=open(file)
    lines=fl.readlines()
    fl.close()
    return lines

def Blocks(file):
    blocks= []
    block = ''
    lines = Readlines(file)
    for line in lines:
        if line.strip():
            block = block+line
        elif block: 
            blocks.append(block)
            block=''
    return blocks

if __name__ == '__main__':
    blocks = Blocks()
    for i in blocks:
        print i
