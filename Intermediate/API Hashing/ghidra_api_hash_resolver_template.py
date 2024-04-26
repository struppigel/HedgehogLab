#Resolve API hashes and add API names as comments
#@author Karsten Hahn
#@category Modification
#@keybinding 
#@menupath 
#@toolbar 

from ghidra.program.model.scalar import Scalar
from ghidra.program.model.listing import CodeUnit

def find_api_for_hash(req_hash):
	#TODO

register = "R10D"
address_view = currentProgram.getMemory().getExecuteSet()
it = address_view.getAddresses(True)

while it.hasNext():
	address = it.next()
	inst = getInstructionAt(address)
	if inst is None:
		continue
            
	mnemonic = inst.getMnemonicString()
	if mnemonic == "MOV":
		first_op = inst.getOpObjects(0)[0]
		if first_op.toString() == register:
			second_op = inst.getOpObjects(1)[0]
			if isinstance(second_op, Scalar):
				value = second_op.getValue()
				decoded_api = find_api_for_hash(value)	
				if decoded_api:
					inst.setComment(CodeUnit.EOL_COMMENT, decoded_api)
					print('found api', decoded_api)
				else:
					print('did not find an api for hash', hex(value))