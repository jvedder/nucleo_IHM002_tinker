import math

num_points = 360
max_value = 1024


half_max_value = max_value / 2
sine = [] 
for i in range(num_points):
    s = math.sin( i/num_points * 2 * math.pi )
    sine.append( round(s * (half_max_value -1) + half_max_value) )

print('max', max(sine))
print('min', min(sine))
print('len', len(sine))

indent = '    '

file = 'sine['+str(num_points)+'].txt'
print('Writing ' + file)
with open(file, mode='w', encoding='utf-8') as f:
    f.write('const uint16_t sine['+str(num_points)+'] = {\n' + indent)
    count = 0
    for (index, s) in enumerate(sine):
        f.write(str(s).rjust(4) + ',')
        count += 1
        if count == 16:
            f.write('\n' + indent)
            count = 0
    f.write('};\n')

file = 'sine['+str(num_points)+'].csv'
print('Writing ' + file)
with open(file, mode='w', encoding='utf-8') as f:
    f.write('index,sine\n')
    count = 0
    for (index, s) in enumerate(sine):
        f.write(str(index) + ',' + str(s) + '\n')
print ('Done') 
