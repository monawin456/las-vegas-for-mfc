
// LasVegasMFCDoc.h : interface of the CLasVegasMFCDoc class
//


#pragma once
class Player;
class Casino;
class BillDeck;

class CLasVegasMFCDoc : public CDocument
{
protected: // create from serialization only
	CLasVegasMFCDoc();
	DECLARE_DYNCREATE(CLasVegasMFCDoc)

// Attributes
public:
	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;
	Player* player5;

	Casino *casino1;
	Casino *casino2;
	Casino *casino3;
	Casino *casino4;
	Casino *casino5;
	Casino *casino6;

	BillDeck *billDeck;

	int round;

	BOOL continueCheck;
	BOOL saveCheck;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CLasVegasMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
