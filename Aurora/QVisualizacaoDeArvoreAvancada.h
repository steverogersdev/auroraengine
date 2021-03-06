#pragma once

#include <QTreeView>
#include <deque>

class QModelIndex;
class QPersistentModelIndex;
class QAbstractItemModel;
class QItemSelectionModel;

class CIndiceDeModeloPersistenteAvanšado
{
	public:
		CIndiceDeModeloPersistenteAvanšado(const QModelIndex& indice);

		QModelIndex ConverterParaIndice() const;

	private:
		QPersistentModelIndex m_indicePersistente;
		const uint m_coluna;
		const QAbstractItemModel* m_modelo;
		std::deque<quintptr> m_identificadores;
};

class QVisualizacaoEmArvoreAvancada : public QTreeView
{
	public:
		QVisualizacaoEmArvoreAvancada();
		~QVisualizacaoEmArvoreAvancada();

		static QModelIndex ConverterParaOriginal(QModelIndex& indice, QAbstractItemModel* pModeloDeVisualizacao);
		static QModelIndex ConverterDoOriginal(QModelIndex& indice, QAbstractItemModel* pModeloDeVisualizacao);
		static void SalvarSelecao(std::vector<CIndiceDeModeloPersistenteAvanšado>& armazenamentoDeBackupSelecionado, QAbstractItemModel* pModeloDeVisualizacao, QItemSelectionModel* pModeloDeSelecaoDeVisualizacao);
		static void RestaurarSelecao(std::vector<CIndiceDeModeloPersistenteAvanšado>& armazenamentoDeBackupSelecionado, QAbstractItemModel* pModeloDeVisualizacao, QItemSelectionModel* pModeloDeSelecaoDeVisualizacao);
};

