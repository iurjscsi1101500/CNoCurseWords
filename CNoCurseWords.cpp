#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/AST/AST.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include <set>
#include <algorithm>
#include <cctype>

class CNoCurseWordsVisitor : public clang::RecursiveASTVisitor<CNoCurseWordsVisitor> {
public:
    CNoCurseWordsVisitor(clang::ASTContext &Context, clang::DiagnosticsEngine &Diag)
        : Context(Context), Diag(Diag) {}

    bool VisitStringLiteral(clang::StringLiteral *S) {
        std::set<std::string> curseWords = {"fuck", "ass","bitch"};

        std::string str = S->getString().str();
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);

        if (curseWords.find(str) != curseWords.end()) {
            unsigned DiagID = Diag.getCustomDiagID(clang::DiagnosticsEngine::Error, "CURSES NOT ALLOWED: %0");
            Diag.Report(S->getBeginLoc(), DiagID) << str;
        }

        return true;
    }

private:
    clang::ASTContext &Context;
    clang::DiagnosticsEngine &Diag;
};

class CNoCurseWordsASTConsumer : public clang::ASTConsumer {
public:
    CNoCurseWordsASTConsumer(clang::ASTContext &Context, clang::DiagnosticsEngine &Diag)
        : Visitor(Context, Diag) {}

    void HandleTranslationUnit(clang::ASTContext &Context) override {
        Visitor.TraverseDecl(Context.getTranslationUnitDecl());
    }

private:
    CNoCurseWordsVisitor Visitor;
};

class CNoCurseWordsAction : public clang::PluginASTAction {
protected:
    std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &CI, llvm::StringRef InFile) override {
        return std::make_unique<CNoCurseWordsASTConsumer>(CI.getASTContext(), CI.getDiagnostics());
    }

    bool ParseArgs(const clang::CompilerInstance &CI, const std::vector<std::string> &args) override {
        return true; // No arguments to parse
    }
};

static clang::FrontendPluginRegistry::Add<CNoCurseWordsAction> X("CNoCurseWords", "Detect curse words (so noobs don't curse)");

