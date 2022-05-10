createRecord()
{
	echo "The name of the database is addressbook.txt"
	touch addressbook.txt
	if [ "addressbook.txt" ]
	then
		echo "File has been created successfully!"
	else
		echo "File creation failed!"
	fi
}
insertRecord()
{
	echo "Enter the name:"
	read name
	echo "Enter the phone number"
	read pnumber
	echo "Enter the pincode"
	read pincode
	echo "Enter the city name:"
	read city
	echo "$name   $pnumber  $pincode    $city">>addressbook.txt
	echo "Record inserted successfully!"
}
displayRecord()
{
	echo ""
	echo "Records Found:"
	echo "Name  PhoneNumber  Pincode City"
	cat addressbook.txt

}
searchRecord()
{
	echo "Enter the name of the person to searched:"
	read name
	echo ""
	grep -w "$name" addressbook.txt
	output=$?
	if [ $output = 0 ]
	then	
		echo ""
	else
		echo "Records Not Found!"
	fi
	
}
deleteRecord()
{
	echo "Enter the name of the person to deleted:"
	read name
	grep -v "$name" addressbook.txt>temp.txt
	mv temp.txt addressbook.txt
	echo "Record has been successfully deleted!"
}
modifyRecord()
{
	echo "Enter the name whose record has to be modified:"
	read name
	grep -v "$name" addressbook.txt>temp.txt
	echo "Enter new name:"
	read newname
	echo "Enter new phone number:"
	read phnumber
	echo "Enter new pincode:"
	read pincode
	echo "Enter new city:"
	read city
	echo "$newname $phnumber $pincode $city">>temp.txt
	mv temp.txt addressbook.txt
	echo "Record has been successfully modified!"
}
ch=0
while [ $ch -lt 7 ]
do
	echo ""
	echo ""
	echo "MENU"
	echo "1. Create Address Book"
	echo "2. Insert record in the address book"
	echo "3. Display Address Book"
	echo "4. Search for a record in the Address Book"
	echo "5. Delete a Record"
	echo "6. Modify a Record"
	echo "7. EXIT"
	echo ""
	echo "Enter your choice"
	read ch
	case $ch in
		1) createRecord;;
		2) insertRecord;;
		3) displayRecord;;
		4) searchRecord;;
		5) deleteRecord;;
		6) modifyRecord;;
		7) echo "Thank You!"
	esac
done



