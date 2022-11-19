#!/bin/bash
createAddressBook()
{
		#echo
		if [ -e $addressbook.txt ]
	then
		echo "Addressbook already created"
	else
		
		touch addressbook.txt
		echo "Address book created"
		fi
}
insertaRecord()
{
	echo
	while true
	do
		echo "To insert a record to your address book, please enter the information in this"
		echo "format: \"Last name,first name,email url,phone number\" (no quotes or spaces)."
		echo "Example: Doe,John,johndoe@gmail.com,6501234567"
		echo "If you'd like to quit, enter 'q'."
		read aInput
		if [ "$aInput" == 'q' ]
			then
			break
		fi
		echo
		echo $aInput >> addressbook.txt
		echo "The entry was added to your address book."
		echo
	done
}

viewaRecord()
{
	echo
	while true
	do
		echo "To view a record, enter the last name of the person (case sensitive)."
		echo "If you'd like to quit, enter 'q'."
		read dInput
		if [ "$dInput" == 'q' ]
			then
			break
		fi
		echo
		echo "Listing records for \"$dInput\":"
		grep ^"$dInput" addressbook.txt  # searching the lines by last name (the first field in the record)
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "No records found with last name of \"$dInput\"."
		fi
		echo
	done
}

modifyaRecord()
{
	echo
	while true
	do
		echo "To modify 	a record, enter any search string, e.g. last name or email address (case sensitive)."
		echo "If you're done editing your address book, enter 'q' to quit."
		read eInput
		if [ "$eInput" == 'q' ]
			then
			break
		fi
		echo
		echo "Listing records for \"$eInput\":"
		grep -n "$eInput" addressbook.txt
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "No records found for \"$eInput\""
		else
			echo
			echo "Enter the line number (the first number of the entry) that you'd like to edit."
			read lineNumber
			echo
			for line in `grep -n "$eInput" addressbook.txt`
			do
				number=`echo "$line" | cut -c1`
				if [ $number -eq $lineNumber ]
					then
					echo "What would you like to change it to? Use the format:"
					echo "\"Last name,first name,email url,phone number\" (no quotes or spaces)."
					read edit
					lineChange="${lineNumber}s"
					sed -i -e "$lineChange/.*/$edit/" addressbook.csv
					echo
					echo "The change has been made."
				fi
			done
		fi
		echo
	done		
}

removeRecord()
{
	echo 
	while true
	do
		echo "To remove a record, enter any search string, e.g. last name or email address (case sensitive)."
		echo "If you're done, enter 'q' to quit."
		read rInput
		if [ "$rInput" == 'q' ]
			then
			break
		fi
		echo
		echo "Listing records for \"$rInput\":"
		grep -n "$rInput" addressbook.txt
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "No records found for \"$rInput\""
		else
			echo
			echo "Enter the line number (the first number of the entry) of the record you want to remove."
			read lineNumber
			for line in `grep -n "$rInput" addressbook.csv`
			do
				number=`echo "$line" | cut -c1`
				if [ $number -eq $lineNumber ]
					then
					lineRemove="${lineNumber}d"
					sed -i -e "$lineRemove" addressbook.txt
					echo "The record was removed from the address book."
				fi
			done
		fi
		echo
	done
}

searchRecord()
{
	echo
	while true
	do
		echo "To search for a record, enter any search string, e.g. last name or email address (case sensitive)."
		echo "The format of a record is \"Last name,firstname,email address,phone number\"."
		echo "Example: Doe,John,johndoe@gmail.com,6501234567"
		echo "If you'd like to quit, enter 'q'."
		read sInput
		if [ "$sInput" == 'q' ]
			then
			break
		fi
		echo
		echo "Listing records for \"$sInput\":"
		grep "$sInput" addressbook.txt
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "No records found for \"$sInput\"."
		fi
		echo
	done
}

echo "Adress book?"
echo "enter your choice"
echo "1--->Create address book"
echo "2--->Insert a record"
echo "3--->View one or more records"
echo "4--->Modify a record"
echo "5--->Delete a single record"
echo "6--->Search for records"
echo "7--->exit"
echo
read input
case $input in
	1)createAddressBook;;
	2)insertaRecord;;
	3)viewaRecord;;
	4)modifyaRecord;;
	5)removeRecord;;
	6)searchRecord;;
esac



