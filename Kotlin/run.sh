A=$1
kotlinc $A -include-runtime -d a.jar
java -jar a.jar