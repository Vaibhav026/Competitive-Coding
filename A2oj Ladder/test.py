x = object()
y = object()

# TODO: change this code
x_list = [x]
y_list = [y]

x_list = x_list*10
y_list = y_list*10
big_list = x_list + y_list

print("x_list contains %d objects" % len(x_list))
print("y_list contains %d objects" % len(y_list))
print("big_list contains %d objects" % len(big_list))

# testing code
if x_list.count(x) == 10 and y_list.count(y) == 10:
    print("Almost there...")
if big_list.count(x) == 10 and big_list.count(y) == 10:
    print("Great!")






	import hammingDistance from '../hammingDistance';

describe('hammingDistance', () => 
	{
  it('should throw an error when trying to compare the strings of different lengths', () => {
    const compareStringsOfDifferentLength = () => {
      hammingDistance('a', 'aa');
    };

    expect(compareStringsOfDifferentLength).toThrowError();
  });

  it('should calculate difference between two strings', () => {
    expect(hammingDistance('a', 'a')).toBe(0);
    expect(hammingDistance('a', 'b')).toBe(1);
    expect(hammingDistance('abc', 'add')).toBe(2);
    expect(hammingDistance('karolin', 'kathrin')).toBe(3);
    expect(hammingDistance('karolin', 'kerstin')).toBe(3);
    expect(hammingDistance('1011101', '1001001')).toBe(2);
    expect(hammingDistance('2173896', '2233796')).toBe(3);
  });
});       