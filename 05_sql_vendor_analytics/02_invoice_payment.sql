SELECT VendorContactFName, VendorContactLName, VendorName
FROM Vendors
SORT ORDER BY VendorContactLName, VendorContactFName

SELECT InvoiceNumber, InvoiceTotal, PaymentTotal + CreditTotal AS TotalCredits, InvoiceTotal - PaymentTotal + CreditTotal AS BalanceDue
FROM Invoices
WHERE InvoiceTotal >= 500 OR InvoiceTotal <= 10000

SELECT VendorContactFName, VendorContactLName,
	VendorContactFName + ' ' + VendorContactLName AS FullName
FROM Vendors
WHERE VendorContactLName < 'D' OR VendorContactLName = 'E'
ORDER BY VendorContactLName, VendorContactFName




SELECT InvoiceTotal,
	InvoiceTotal / 10 AS PercentOf10,
	(InvoiceTotal) + 10 AS PlusPercentOf10
FROM Invoices


SELECT *
FROM Invoices
WHERE PaymentDate is NULL

SELECT *
FROM Invoices
WHERE PaymentDate is NOT NULL