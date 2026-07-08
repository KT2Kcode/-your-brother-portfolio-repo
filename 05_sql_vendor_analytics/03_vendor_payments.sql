/* CHAPTER 13 */
USE AP;

/* 1 */
CREATE VIEW InvoiceBasic
AS
SELECT VendorName, InvoiceNumber, InvoiceTotal
FROM Vendors JOIN Invoices
ON Vendors.VendorID = Invoices.VendorID;

SELECT *
FROM InvoiceBasic
WHERE VendorName LIKE '[N-P]%'
ORDER BY VendorName;

/* 2 */
CREATE VIEW Top10PaidInvoices
AS
SELECT TOP 10 VendorName,
	MAX(InvoiceDate) AS LastInvoice,
	SUM(InvoiceTotal) AS SumOfInvoices
FROM Vendors JOIN Invoices
ON Vendors.VendorID = Invoices.VendorID
WHERE InvoiceTotal - CreditTotal - PaymentTotal = 0
GROUP BY VendorName
ORDER BY SUM(InvoiceTotal) DESC;

/* 3 */
CREATE VIEW VendorAddress
AS
SELECT VendorID, VendorAddress1, VendorAddress2, VendorCity, VendorState, VendorZipCode
FROM Vendors;

SELECT *
FROM VendorAddress
WHERE VendorID = 4;

UPDATE VendorAddress
SET VendorAddress1 = '2010 West Drive',
	VendorAddress2 = 'Ste 260'
WHERE VendorID = 4;

/* 4 */
SELECT *
FROM sys.foreign_keys;

/* 5 */
/* See Picture - Exercise 13-5 */
