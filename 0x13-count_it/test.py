import re
string = 'java'
txt = 'javascript con javab. eventing deep dive.'

expresion = re.compile(string + '[\s,.]')
if re.search(expresion, txt):
    print('encontrado')
else:
    print('no encontrado')
