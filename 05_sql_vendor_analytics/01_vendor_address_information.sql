USE AP;

/* 1 */
DROP TABLE InvoiceCopy;
DROP TABLE VendorCopy;

SELECT *
INTO InvoiceCopy
FROM Invoices;

SELECT *
INTO VendorCopy
FROM Vendors;

/* 2 */
INSERT InvoiceCopy
VALUES (32, 'AX-014-027', '2016-06-21', 434.58, 0, 0, 2, '2016-07-08', NULL);

/* 3 */
INSERT VendorCopy
SELECT VendorName, VendorAddress1, VendorAddress2,
	   VendorCity, VendorState, VendorZipCode,
	   VendorPhone, VendorContactLName, VendorContactFName,
	   DefaultTermsID, DefaultAccountNo
FROM Vendors
WHERE VendorState <> 'CA';

/* 4 */
UPDATE VendorCopy
SET DefaultAccountNo = 403
WHERE DefaultAccountNo = 400;

/* 5 */
UPDATE InvoiceCopy
SET PaymentDate = GETDATE(),
	PaymentTotal = InvoiceTotal - CreditTotal
WHERE InvoiceTotal - CreditTotal - PaymentTotal > 0;

/* 6 */
UPDATE InvoiceCopy
SET TermsID = 2
WHERE VendorID IN
	(SELECT VendorID
	 FROM VendorCopy
	 WHERE DefaultTermsID = 2);

/* 7 */
UPDATE InvoiceCopy
SET TermsID = 2
FROM InvoiceCopy JOIN VendorCopy
  ON InvoiceCopy.VendorID = VendorCopy.VendorID
WHERE DefaultTermsID = 2;

/* 8 */
DELETE VendorCopy
WHERE VendorState = 'MN';

/* 9 */
DELETE VendorCopy
WHERE VendorState NOT IN
  (SELECT DISTINCT VendorState
   FROM VendorCopy JOIN InvoiceCopy
     ON VendorCopy.VendorID = InvoiceCopy.VendorID);