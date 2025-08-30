# @category Strings
# Use this script before Ghidra 11.4.1

from ghidra.program.model.data import StringDataInstance, TranslationSettingsDefinition
from ghidra.program.util import DefinedDataIterator
from ghidra.app.script import GhidraScript
from util import CollectionUtils

def translate_string(s):
    # customize here
    return "TODO " + s + " TODO"

count = 0
listing = currentProgram.getListing()
num_defined_data = listing.getNumDefinedData()

monitor.initialize(num_defined_data)
monitor.setMessage("Translating strings")

for data in CollectionUtils.asIterable(DefinedDataIterator.definedStrings(currentProgram, currentSelection)):
    if monitor.isCancelled():
        break
    str_data_instance = StringDataInstance.getStringDataInstance(data)
    s = str_data_instance.getStringValue()
    
    if s is not None:
        TranslationSettingsDefinition.TRANSLATION.setTranslatedValue(data, translate_string(s))
        TranslationSettingsDefinition.TRANSLATION.setShowTranslated(data, True)
        count += 1
        monitor.incrementProgress(1)

println("Translated " + str(count) + " strings.")